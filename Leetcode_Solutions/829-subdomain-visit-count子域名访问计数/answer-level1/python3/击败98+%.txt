### 解题思路
1.本题的重点在于分解字符串，界定符选取“.”
2.另外需要结合string.split('.',maxsplit=1)，表示只分解第一个界定符

### 代码

```python3
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        hash_map={}
        res=[]
        for string in cpdomains:
            count=int(string.split()[0])
            sub_str=string.split()[1]
            if sub_str in hash_map:
                hash_map[sub_str]+=count
            else:
                hash_map[sub_str]=count
            if string.count('.')==2:  #字符串为 x.y.z模式
                subdomain_low=string.split('.',maxsplit=1)[1]
                subdomain_high=subdomain_low.split('.')[1]
                if subdomain_low in hash_map:
                    hash_map[subdomain_low]+=count
                else:
                    hash_map[subdomain_low]=count
                if subdomain_high in hash_map:
                    hash_map[subdomain_high]+=count
                else:
                    hash_map[subdomain_high]=count
            elif string.count('.')==1: #字符串为 y.z模式
                subdomain=string.split('.')[1]
                if subdomain in hash_map:
                    hash_map[subdomain]+=count
                else:
                    hash_map[subdomain]=count
        for key,value in hash_map.items():
            res.append(str(value)+' '+key)
        return res
```