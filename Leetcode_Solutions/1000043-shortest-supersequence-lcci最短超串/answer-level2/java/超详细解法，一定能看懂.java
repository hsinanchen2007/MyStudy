## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)



#### 解法1

**【数据结构】**
* map

**【思路】**
1. 将`small`数组中的数存在`map`中，其`value`初始化为`-1`
2. 遍历`big`数组，`map`存储`small`数组中每一个值在`big`数组中的位置，并更新
3. 当在`big`数组中找齐了所有在`small`数组中的数字后，就用当前下标`i`减去`map`中`value`的最小值（**即位置的最小值**），得到的差即为“**包含短数组所有的元素的子数组长度**”
4. 时间复杂度为`O(nm)`



**【代码】**
```java
public int[] shortestSeq(int[] big, int[] small) {
   if(small.length>big.length)
       return new int[0];
   Map<Integer,Integer> map=new HashMap<>();
   int count=small.length;
   int[] ans={0,big.length};
   
   for(int i:small)
       map.put(i,-1);
       
   for(int i=0;i<big.length;i++){
       if(map.containsKey(big[i])){
           if(map.get(big[i])==-1)
               count--;
           map.put(big[i],i);
       }
       if(count<=0){
           Collection<Integer> c = map.values();
           Object[] obj = c.toArray();
           int minNum=getMin(obj);
           if(i-minNum+1<ans[1]-ans[0]+1){
               ans[0]=minNum;
               ans[1]=i;
           }
       }
   }
   if(count>0)
       return new int[0];
   return ans;
}
int getMin(Object[] obj){
    int minNum=Integer.MAX_VALUE;
    for(Object i:obj){
        minNum=Math.min((int)i,minNum);
    }
    return minNum;
}
```
**【备注】**
* 由于需要找到所有`value`的最小值，所以在`m!=n`的情况下，复杂度难免要达到`O((n-m)m+(n-m))`，下面有一个优化版本


#### 解法2


**【数据结构】**
* map
* set
* list

**【思路】**
1. 用两个`set`分别存`small`数组中的值和`big`数组中的值
2. `map`用于计数
3. `list`用于存储下标
4. 将`small`数组中的值存入`smallSet`
5. 遍历`big`数组，如果`big[i]`在`small`数组中，那么将其下标存储在`list`中，将其值存在`bigSet`中。并在`map`中对其进行计数
6. 如果`bigSet.size() == smallSet.size()`，那么就删除`list`头部元素和`map`中对应的计数，直至`map`中的`value`出现0为止，这样的操作保证了最先进来的重复数会被`remove`，然后再计算长度。**其思想和第一种方法类似**。



**【代码】**
```java
public int[] shortestSeq(int[] big, int[] small) {
    int b_len = big.length;
    if (b_len < small.length)
        return new int[0];
    HashSet<Integer> smallSet = new HashSet<>(), bigSet = new HashSet<>();
    HashMap<Integer, Integer> map = new HashMap<>();
    List<Integer> list = new ArrayList<>();
    for (int s : small)
        smallSet.add(s);
    int len = Integer.MAX_VALUE;
    int[] ans={-1,-1};
    for (int i = 0; i < b_len; ++i) {
        if (smallSet.contains(big[i])) {
            list.add(i);
            bigSet.add(big[i]);
            if(map.containsKey(big[i]))
                map.put(big[i],map.get(big[i])+1);
            else
                map.put(big[i],1);

            if (bigSet.size() == smallSet.size()) {
                int temp;
                while (true) {
                    temp = list.remove(0);
                    int count = map.get(big[temp]) - 1;
                    map.put(big[temp], count);
                    if (count == 0) {
                        bigSet.remove(big[temp]);
                        break;
                    }
                }
                if (len > i - temp + 1) {
                    len = i - temp + 1;
                    ans[0] = temp;
                    ans[1] = i;
                }
            }
        }
    }
    if(ans[0]<0)
        return new int[0];
    return ans;
}
```
**【备注】**
* 方法一更容易理解

**【关注微信公众号，带你拿大厂offer】**

![logo_gif.gif](https://pic.leetcode-cn.com/f6d7085de4095860835e77030f7fd659dc589c02e9fbc0ed5e125ca913d1b15f-logo_gif.gif)
