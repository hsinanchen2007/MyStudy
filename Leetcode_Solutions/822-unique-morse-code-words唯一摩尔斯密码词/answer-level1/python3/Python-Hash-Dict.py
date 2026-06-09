```
m = [".-","-...","-.-.","-..",".","..-.","--.",
                 "....","..",".---","-.-",".-..","--","-.",
                 "---",".--.","--.-",".-.","...","-","..-",
                 "...-",".--","-..-","-.--","--.."]
        w = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
        d = dict(zip(w,m))
        #print("d",d.items())
        temp=set()
        for i in words:
            temp_morse=[]
            for j in i:
                temp_morse.append(d[j])
                #print("temp_morse",temp_morse)
            s="".join(temp_morse)
            #print("s",s)
            temp.add(s)
            #print("temp",temp)
        return len(temp)
```
