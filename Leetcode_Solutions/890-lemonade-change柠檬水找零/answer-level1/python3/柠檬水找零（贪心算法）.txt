- **题意理解：**
    - 一个柠檬 $5$ 元，因此：顾客付 $10$ 元找 $5$ 元，付 $20$ 元需找 $15$ 元；
    - 找零方案有：`10 = (5) + 5`，`20 = (10+5) + 5 = (5+5+5) + 5`，其中小括号中是找零部分。
    - 可以看出，10元只能用5元找零，而20元则可以用10元或5元找零并有两种组合。
- **贪心策略：** $2$ 个 $5$ 元等价于 $1$ 个 $10$ 元。需要尽可能地多留 $5$ 元在手上，防止 $10$ 元的顾客无法找零。
- **模拟过程：** 
    - 付 $5$ 元：记录；
    - 付 $10$ 元： 找 $5$ 元；
    - 付 $20$ 元： 优先找 $10+5$ 组合，若没有则找 $5+5+5$ 组合。
- **提前返回：** 在模拟过程中，若发现手上没有足够的零钱找零，则直接返回`false`。

```python []
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five, ten = 0, 0
        for b in bills:
            if b == 5:
                five += 1
            elif b == 10:
                if not five: return False
                five -= 1
                ten += 1
            else:
                if ten and five:
                    ten -= 1
                    five -= 1
                elif five > 2:
                    five -= 3
                else:
                    return False
        return True
```

```java []
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five = 0, ten = 0;
        for(int b : bills){
            if(b == 5) five ++;
            else if(b == 10) {
                if(five-- == 0) return false;
                ten++;
            }
            else {
                if(five > 0 && ten > 0){
                    five--; ten--;
                }
                else if(five > 2){
                    five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
}
```