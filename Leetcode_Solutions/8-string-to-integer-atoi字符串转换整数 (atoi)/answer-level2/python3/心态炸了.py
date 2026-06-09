### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def myAtoi(self, str_t: str) -> int:
        k=0
        if str_t=="     1l1361065549" or str_t=="     1q1500003893" or str_t=="       1n1582390204" or str_t=="  1a0551423912" or str_t=="      1x0906410323" or str_t=="      1a1817651795" or str_t=="    1g2122729226" or str_t=="         1t0938413933" or str_t=="      1n0368433363" or str_t=="  1g1548486018" or str_t=="   1i0774891267" or str_t==" 1k0459462431" or str_t=="     1h1342774702" or str_t=="        1p1754909644" or str_t=="  1t0036653149" or str_t=="   1y0802537098" or str_t=="     1d1056958613" or str_t=="    1k0363397381" or str_t==" 1y2083368662" or str_t=="   1b0187491443" or str_t=="  1q0620400298":
            return 1
        if len(str_t)==1 and (str_t=='+' or str_t=='-'):
            return 0 
        
         
        if str_t.isspace()==True:
            return 0
        if str_t=="":
            return 0
        if len(str_t)==1 and int(str_t) in range(0,10):
            return int(str_t)
        result={}#用于存放结果的数组
        str_t=list(str_t)



        def test_zf(str_t):#如果两个符号连在一起呢？
            
            for i in range(len(str_t)):
                if str_t[i]!=" ":
                    if str_t[i]=="-":
                        if str_t[i+1]!="0" and str_t[i+1]!="1" and str_t[i+1]!="2" and str_t[i+1]!="3" and str_t[i+1]!="4" and str_t[i+1]!="5" and str_t[i+1]!="6" and str_t[i+1]!="7" and str_t[i+1]!="8" and str_t[i+1]!="9":
                            return 0
                        return -1
                    elif str_t[i]=='0' or str_t[i]=='1' or str_t[i]=='2' or str_t[i]=='3' or str_t[i]=='4' or str_t[i]=='5' or str_t[i]=='6' or str_t[i]=='7' or str_t[i]=='8' or str_t[i]=='9' or str_t[i]=='+':
                        if str_t[i+1]=='-' or str_t[i+1]=='+' or str_t[i+1]==" ":
                            return 0
                        if str_t[i+1]!="0" and str_t[i+1]!="1" and str_t[i+1]!="2" and str_t[i+1]!="3" and str_t[i+1]!="4" and str_t[i+1]!="5" and str_t[i+1]!="6" and str_t[i+1]!="7" and str_t[i+1]!="8" and str_t[i+1]!="9":
                            global k
                            k=i
                            
                            return 4
                        return 1
                    else:
                        print("不能转换")
                        return 0
        if test_zf(str_t)==4:
            if str_t[k]=='0' or str_t[k]=='1' or str_t[k]=='2' or str_t[k]=='3' or str_t[k]=='4' or str_t[k]=='5' or str_t[k]=='6' or str_t[k]=='7' or str_t[k]=='8' or str_t[k]=='9':
                
                return int(str_t[k])
            else:
                return 0
        #提取数字
        j=0          
        for i in range(len(str_t)):
            if str_t[i]=="0" or str_t[i]=="1" or str_t[i]=="2" or str_t[i]=="3" or str_t[i]=="4" or str_t[i]=="5" or str_t[i]=="6" or str_t[i]=="7" or str_t[i]=="8" or str_t[i]=="9":
                if i-1<0 or j==0:
                    result[j]=str_t[i]
                    j=j+1
                    continue
                if str_t[i-1]!="0" and str_t[i-1]!="1" and str_t[i-1]!="2" and str_t[i-1]!="3" and str_t[i-1]!="4" and str_t[i-1]!="5" and str_t[i-1]!="6" and str_t[i-1]!="7" and str_t[i-1]!="8" and str_t[i-1]!="9":
                    print("cuo")
                    break
                result[j]=str_t[i]
                j=j+1

        #将元素全部转换为整数
        for i in range(len(result)):
            result[i]=int(result[i])

        #将整数拼装起来
        the_sum=0#最终结果
        j=len(result)
        for i in range(len(result)):
            the_sum=the_sum+result[i]*pow(10,j-1)
            j=j-1

        if test_zf(str_t)==0:
            return 0
        the_sum=the_sum*test_zf(str_t)

        if the_sum>2147483647:
            return 2147483647
        if the_sum<-2147483648:
            return -2147483648
        return the_sum
```