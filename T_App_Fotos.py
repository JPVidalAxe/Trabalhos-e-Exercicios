import pickle

def anterior(login1,login2,usuarios):
    seguidores1 = len(usuarios[login1][2])
    seguidores2 = len(usuarios[login2][2])
    seguem1 = len(usuarios[login1][1])
    seguem2 = len(usuarios[login2][1])
    nome1 = usuarios[login1][0]
    nome2 = usuarios[login2][0]
    
    if seguidores1 < seguidores2:   return True
    if seguidores1 > seguidores2:   return False

    if seguem1 < seguem2: return True
    if seguem1 > seguem2: return False

    if nome1 > nome2: return True
    if nome1 < nome2: return False

    if login1 > login2: return True
    if login1 < login2: return False
   
        
    





def qsort(l,usuarios):
    if len(l) <= 1:
        return l
    else:
        pivot = l[0]
        maiores = []
        menores = []
        for i in range(1,len(l)):
            if anterior(l[i],pivot,usuarios):
                menores.append(l[i])
            else:
                maiores.append(l[i])
        return qsort(maiores,usuarios) + [pivot] + qsort(menores,usuarios)



def data(post1,post2):
    ano1 = post1[3][2]
    ano2 = post2[3][2]
    mes1 = post1[3][1]
    mes2 = post2[3][1]
    dia1 = post1[3][0]
    dia2 = post2[3][0]
    hora1 = post1[3][3]
    hora2 = post2[3][3]
    minuto1 = post1[3][4]
    minuto2 = post2[3][4]
    login1 = post1[0]
    login2 = post2[0]

    if ano1 > ano2:   return True
    if ano1 < ano2:   return False

    if mes1 > mes2: return True
    if mes1 < mes2: return False

    if dia1 > dia2: return True
    if dia1 < dia2: return False

    if hora1 > hora2: return True
    if hora1 < hora2: return False

    if minuto1 > minuto2 : return True
    if minuto1 < minuto2 : return False

    if login1 < login2 : return True
    if login1 > login2 : return False




def qsort2(l1):
    if len(l1) <= 1:
        return l1
    else:
        pivot = l1[0]
        maiores = []
        menores = []
        for i in range(1,len(l1)):
            if data(l1[i],pivot):
                maiores.append(l1[i])
            else:
                menores.append(l1[i])
        return qsort2(maiores) + [pivot] + qsort2(menores)



    
        









def main():
    l = []
    l1 = []
    with open('usuarios.bin','rb') as f,open('saida.txt','w') as a:
        usuarios = pickle.load(f)
    
        for login in usuarios:
            l.append(login)
        
        l = qsort(l,usuarios)
        
        
        for login in l:
            a.write(f'{usuarios[login][0]} (segue {str(len(usuarios[login][1]))}, seguido por {str(len(usuarios[login][2]))})\n')
    
        first = l[0]
        nome = usuarios[first][0]
        follow = usuarios[first][1]
        
        
        for login in follow: 
            for titulo,legenda,data in usuarios[login][3]:
                    l1.append((login,titulo,legenda,data))
            
        l1 = qsort2(l1)
            
        a.write('---\n')

        a.write(f'Feed De {nome}:\n')
    
        a.write('***\n')
        
        for log_user,npost,lpost,dpost in l1:
            a.write(f'{log_user}\n')
            a.write(f'{npost}\n')
            a.write(f'{lpost}\n')
            a.write('{:02d}/{:02d}/{} {:02d}:{:02d}.format(dpost[0],dpost[1],dpost[2],dpost[3],dpost[4])
            a.write('***\n')



main()
