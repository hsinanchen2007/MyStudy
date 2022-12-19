### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        result_list=[]
        len_str=len(S)
        while len_str>0:
            new_single_string=S[0]
            print(new_single_string) ########### new string
            if new_single_string=="(":
                # is (
                result_list.append(-1)
            else:
                #is )
                if result_list[len(result_list)-1]==-1:
                    #previous is (
                    del result_list[len(result_list)-1] #del the last element
                    if len(result_list)==0:
                        result_list=[1]
                    else:
                        if result_list[len(result_list)-1]==-1:
                            #is (
                            #print(result_list)
                            result_list.append(1)
                        else:
                            #is num
                            new_num=result_list[len(result_list)-1]+1
                            del result_list[len(result_list)-1] #del the last element
                            result_list.append(new_num)
                else:
                    #previous is num
                    last_num=result_list[len(result_list)-1] 
                    del result_list[(len(result_list)-2):(len(result_list))] # del the last 2 element
                    if len(result_list)==0:
                        result_list=[2*last_num]
                    else:
                        if result_list[len(result_list)-1]==-1: #if the last element is num
                            #is (
                            result_list.append(last_num*2)
                        else:
                            #is num
                            new_num=result_list[len(result_list)-1]+2*last_num
                            del result_list[len(result_list)-1] #del the last element
                            result_list.append(new_num) 
            print(result_list) ############
            #next loop        
            S=S[1:len_str]
            len_str=len(S)
        return result_list[0]
```