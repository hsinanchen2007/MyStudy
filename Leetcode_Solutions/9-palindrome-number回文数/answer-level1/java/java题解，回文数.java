
思路：声明收尾两个指针，每次比较首尾得到的数字，如果首尾数字相同，则首指针往后移，尾指针往前移。
继续对比下一个数字。直到指针到达中间

执行用时 : 58 ms, 在Palindrome Number的Java提交中击败了71.01% 的用户

内存消耗 : 35.2 MB, 在Palindrome Number的Java提交中击败了97.81% 的用户

```
class Solution {

   public boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        if(x < 10){
            return true;
        }

        //首先获取整数位数
        int numCount = getNumCount(x);
       //前面的数字索引
        int firstIndex = 1;
       //后面的数字索引
        int lastIndex = numCount;

        while (firstIndex<=lastIndex){
            int firstNum = getIndexNum(x,firstIndex,numCount);
            int lastNum = getIndexNum(x,lastIndex,numCount);
            if(firstNum != lastNum ){
                return false;
            }
            firstIndex++;
            lastIndex--;
        }

        return true;
    }

    /**
    * 获取整数中的第几位数字
    */
    private int getIndexNum(int value,int index,int numCount){
        int chushu = (int) Math.pow(10,numCount-index);
        return (value/chushu)%10;
    }


    /**
    *获取整数位数
    */
    private int getNumCount(int value){
        int count = 1;
        int firstNum = value;
        while(firstNum >= 10){
            firstNum = firstNum/10;
            count ++;
        }
        return count;

    }
}
```