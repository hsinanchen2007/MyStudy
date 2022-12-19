### 解题思路
和官方程序思路一致，抄录如下：

让我们尝试模拟给每个购买柠檬水的顾客进行找零的过程。最初，我们从没有 5 美元钞票也没有 10 美元钞票的情况开始。

如果顾客支付了 5 美元钞票，那么我们就得到 5 美元的钞票。

如果顾客支付了 10 美元钞票，我们必须找回一张 5 美元钞票。如果我们没有 5 美元的钞票，答案就是 false，因为我们无法正确找零。

如果顾客支付了 20 美元钞票，我们必须找回 15 美元。

如果我们有一张 10 美元和一张 5 美元，那么我们总会更愿意这样找零，这比用三张 5 美元进行找零更有利。

否则，如果我们有三张 5 美元的钞票，那么我们将这样找零。

否则，我们将无法给出总面值为 15 美元的零钱，答案是 false。

### 代码

```java
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int fiveNum = 0;
        int tenNum = 0;
        for(int i = 0 ; i < bills.length ; i++)
        {
        	if(bills[i] == 5)
        	{
        		fiveNum++;
        	}
        	if(bills[i] == 10)
        	{
        		tenNum++;
        		if(fiveNum <= 0)
        		{
        			return false;
        		}
        		fiveNum--;
        	}
        	if(bills[i] == 20)
        	{
        		if(tenNum > 0)
        		{
        			tenNum--;
        			if(fiveNum > 0)
            		{
            			fiveNum--;
            		}
        			else
        			{
        				return false;
        			}
        		}
        		else
        		{
        			if(fiveNum >= 3)
					{
        				fiveNum -= 3;
					}
        			else
        			{
        				return false;
        			}
        		}
        	}
        }
        return true;
    }
}
```