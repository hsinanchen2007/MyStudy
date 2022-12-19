### 解题思路
I just want to try to find all boundary conditions and solve this problem
maybe it is not one effective solution, but to be honesty it give me too much encourage to go on studying in leetcode. Thank you 

### 代码

```python3
class Solution:
    def myAtoi(self, s: str) -> int:
        a={}
        int_max=2**31-1
        int_min=-2**31
#print(int_max,int_min)
        for i in range(10):
            b=str(i)
            #print(type(b))
            cache={b:i}
            a.update(cache)
#print(a)
        cache={"-":-1,"+":-1," ":" "}
        a.update(cache)
#print(a)

        store=[]
        inp_str=s
        count=0
        for i in inp_str:
              if inp_str[0] not in a:
               #print(inp_str[0])
                 break
              else :
                 if i not in a:
                    break
                 if i=="-":
                     
                     count+=1
                     #print(count)
                     if count>1:
                         if store[-1]!=-1 and type(store[-1])==int:
                            continue
                         if store[-1]==-1:
                            break

                         else:     
                            return 0
                     if store!=[]:
                         if -1 not in store:
                            break
                         else:
                            return 0
                 if i=="+":
                       count+=1
                       if count>1:
                           if store[-1]!=-1 and type(store[-1])==int :
                              store.append(-1)
                              continue
                           if store[-1]==-1:
                              break
                           else:
                              return 0
                       if store!=[]:
                           if -1 not in store:
                               continue
                           else:
                               return 0
                 if i==" ":
                     if store==[]:
                       continue
                     else:
                        break
                 for key in a:
                    if i==key:
                       value=a[key]      
                       store.append(value)
        print(store)
        answer=0
        cache=0
        for i in store:
               if i==-1 :
                  cache+=1
                  if cache>1:
                     break
                  else:
                     continue
               answer=answer*10+i
        if "-" in inp_str:
             if store[0]!=-1:
                answer=answer
             else:
               answer=-answer
    #print(answer)
        if answer>int_max:
            return int_max 
        if answer<int_min:
            return int_min
        return answer

```