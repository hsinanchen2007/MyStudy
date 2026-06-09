### 解题思路
#### 1.数据类型转换：
先int转换为str
#### 2.字符x,y的比较规则:
x+y<y+x  -->x<y;  
x+y>y+x  -->y>x；
x+y==y+x -->x==y
如：x=3,y=4  -->34<43   ->x<y
    x=30,y=3 -->303<330 ->x<y
    x=3,y=34 -->334<343 ->x<y
#### 3.依据规则改写sorted
从functools包中导入cmp_to_key.
cmp:包含两个参数x,y;
cmp编写逻辑为：若为"<"返回-1，"=="返回0，">"返回1。
对sorted参数key:key=cmp_to_key(cmp)
同时sorted参数reverse：reverse=True
### 代码

```python3
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        from functools import cmp_to_key
        def rule(a,b):#eg.30<3
            if a+b<b+a:#30+3<3+30->-1
                return -1
            elif a+b>b+a:
                return 1
            else:return 0
        res=''.join(sorted(map(str,nums),key=cmp_to_key(rule),reverse=True))
        return '0' if res[0]=='0' else res
```