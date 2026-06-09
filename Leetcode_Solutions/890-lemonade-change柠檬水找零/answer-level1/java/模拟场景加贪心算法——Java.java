思路：模拟场景加贪心算法，模拟给每个购买柠檬水的顾客进行找零的过程。
<br/><br/>
初始状态：没有 5 美元钞票也没有 10 美元钞票。
<br/><br/>
如果第一个顾客支付了 5 美元，那么我们就得到 一张 5 美元的钞票。否则，无法找零，答案返回false。
<br/><br/>
第一个顾客支付了 5 美元之后的状态：如果顾客支付了 10 美元，我们会得到一张 10 美元的钞票，然后我们必须找回一张 5 美元钞票。如果我们没有 5 美元的钞票，则无法找零，答案返回 false。
<br/><br/>
如果顾客支付了 20 美元，我们会得到一张 20 元钞票，然后我们必须找回 15 美元。此时有两种找零情况：
<br/><br/>
如果我们有至少一张 10 美元钞票，那么我们总会愿意先把 10 美元找零，然后再找零 5 美元，这比直接用三张 5 美元进行找零更有利。
<br/><br/>
否则，如果我们有三张 5 美元的钞票，那么我们将这样找零。
<br/><br/>
否则，无法找零，答案返回 false。
<br/><br/>
拓展：此题可将所求改为求 能否正确找零，若能，请返回正确找零后，手中钞票的最大张数，若不能，请返回-1
<br/><br/>
代码：
```
class Solution {
    public boolean lemonadeChange(int[] bills) {
        if (bills == null || bills.length < 1) {
            return true;
        }
        
        if (bills[0] != 5) {
            return false;
        }
        
        int money[] = new int[3];// 5 10 15
        money[0]++;
        
        for (int i = 1;i < bills.length;i++) {
            switch (bills[i]) {
                case 5:
                    money[0]++;
                    
                    break;
                case 10:
                    money[1]++;
                    money[0]--;
                    
                    if (money[0] < 0) {
                        return false;
                    }
                    
                    break;
                case 20:
                    money[2]++;
                    if (money[1] > 0) {
                        money[1]--;
                    } else {
                        money[0] -= 2;
                    }
                    
                    money[0]--;
                    
                    if (money[0] < 0) {
                        return false;
                    }
                    
                    break;
            }
        }
        
        return true;
    }
}
```

![image.png](https://pic.leetcode-cn.com/d0b5f7e38d2a0beb20811b406a08a50859156c7d62eebdeffa4656d8edd35539-image.png)