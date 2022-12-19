### 解题思路
先对所给数组进行一次排序，找出最小数的长度，
**然后问题转化成找题目中的X。**
经过几次提交失败后明白了原来X是**最小数长度的因数**

下列num()方法是找到最小长度的因数；
下列isGroup则是判断该因数能否满足题意的条件；

*(具体解体过程见注释，比较详细)*

### 代码

```java
class Solution {
      public boolean hasGroupsSizeX(int[] deck) {
        if (deck.length <= 1){
            return false;
        }
        Arrays.sort(deck);
        //第一个元素
        int first = deck[0];
        //初始化最小数的个数
        int x = 1 ;
        //找到最小数的个数x
        for (int i = 1; i < deck.length; i++) {
            if (deck[i] != first){
                if (i == 1){
                    return false;
                }else {
                    x=i;
                    break;
                }
            }else x++;
        }

        return isGroup(num(x),deck);

    }

    //找到num的非1因数并保存
    public List<Integer> num(int num){
        List<Integer> res = new ArrayList<>();
        for (int i = 2; i <= num ; i++) {
            if (num % i == 0){
                res.add(i);
            }
        }
        return res;
    }

    //数组ori能否根据groupSize中因数完成题目的条件
    public boolean isGroup(List<Integer> groupSize,int[] ori){
        if (groupSize == null || groupSize.isEmpty()){
            return false;
        }
        a:for (int size : groupSize){
            //数组长度不能整除因数，肯定不满足条件，直接判断下一因数
            if (ori.length % size != 0){
                continue a;
            }
            int first = ori[0];
            for (int i = 1; i < ori.length; i++) {
                if (i % size != 0){
                    //按照因数大小分割的数组中有长得不一样的整数，不满足条件，判断下一因数
                    if (ori[i] != first) continue a;
                }else {
                    first = ori[i];
                }
            }
            //因为该题是判断能否满足题目条件，所以上面的for循环只要完整循环一次，就代表这个因数满足了条件，返回true即可
            return true;
        }
        //没有因数满足条件，返回false
        return false;
    }
} 
```