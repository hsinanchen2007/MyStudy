### 解题思路
![QQ截图20200217192810.png](https://pic.leetcode-cn.com/dbe4a9a7b73557eb5c0df120a464f08504ea38a6e0413136bf27db8dd04b8a5e-QQ%E6%88%AA%E5%9B%BE20200217192810.png)


### 代码

```python3
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        list_res=[]
        for num in range(1,n+1):
            if num%3==0 and num%5==0:
                list_res.append("FizzBuzz")
            elif num%3==0:
                list_res.append("Fizz")
            elif num%5==0:
                list_res.append("Buzz")
            else:
                list_res.append(str(num))
        return list_res

```