代码报错怎么办, try-catch盖住不就完了. 
公司倒闭了, 嘻嘻.

#### 经过这道题, 我们知道了
##### 当除数为0时:
- c++里除数为0引发的是硬件中断而不是异常;
- js里会根据被除数不同返回不同的值:
    ```
    var a=0/0;      //NaN;

    var a=1/0;      //Infinity;
    ```
#### 可捕获到异常的部分语言
```java []
class Solution {
    public int sumNums(int n) {
        try{
            int a = 1/n;
        } catch(java.lang.ArithmeticException e){
            // 仅仅针对整数
            return n;
        }
        return n + sumNums(n - 1);
    }
}
```
```python []
class Solution:
    def sumNums(self, n: int) -> int:
        # if n != 0:
        try:
            # continue
            1 / n
        # else:
        except:
            return n
        # 上接continue
        return n + self.sumNums(n - 1)
```
```ruby []
# @param {Integer} n
# @return {Integer}
def sum_nums(n)
    begin
        1/n
    rescue
        return 0
    end
    n + sum_nums(n - 1)
end
```

