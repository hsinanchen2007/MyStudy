
python
```
class Solution:
    def countAndSay(self, n: int) -> str:
        print("n = ", n)
        if n==1:
            return "1"
        num = 1 #代表数字
        i = 1 #代表序号
        while i< n:
            num_list = list(str(num))
            print("num = ",num)
            out_str = ''
            value = 0
            count = 0
            j = 0 #慢指针
            for k in range(len(num_list)): #快指针
                if num_list[k] == num_list[j]:
                    count += 1
                    if k == len(num_list)-1:
                        out_str = out_str + str(count) + str(num_list[k-1])
                else:
                    out_str = out_str + str(count) + str(num_list[k-1])
                    j = k
                    count = 1
                    if k == len(num_list)-1:
                        out_str = out_str + str(count) + str(num_list[k]) 

            # print("out_str = ",out_str)
            num = int(out_str)
            i += 1
        return str(num)   

```


java
