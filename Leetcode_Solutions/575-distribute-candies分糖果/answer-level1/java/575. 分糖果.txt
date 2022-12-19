/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/25
 *
 * 解题思路: 不用分，主要使用 hashSet 来记录当前一共有多少种糖
 * 大于length/2 则最多可以分length/2种 否则最多可以分hashSet.size()
 *
 */
```
 public int distributeCandies(int[] candies) {
    HashSet<Integer> hashSet = new HashSet<>();

    int type = 0;
    for(int i = 0;i < candies.length;i++){
        hashSet.add(candies[i]);
    }

    if(hashSet.size() >= candies.length/2){
        return candies.length/2;
    }else{
        return hashSet.size();
    }
}
```