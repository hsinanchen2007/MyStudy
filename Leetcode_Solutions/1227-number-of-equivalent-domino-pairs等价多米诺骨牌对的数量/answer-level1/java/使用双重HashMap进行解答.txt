
## 解题思路
1. 本题对算法复杂度的要求较高，使用暴力的方式用时太大
2. 利用`HashMap`的特性来优化算法的复杂度
3. 改变`数字对`内两个数字的顺序不会影响最终结果,所以将所有多米诺骨牌 数值均改成 从小到大的顺序
4. 一级map的`key1`为`数字对`第一位的值,`value1`为二级map
5. 二级map的`key2`为`数字对`第二位的值,`value2`为该数字对的出现次数
6. 例如`[[1,2],[2,1],[3,4],[5,6]]` 存储进Map之后的值为

|key1| key2 |value2|
|--|--|--|
| 1 | 2 | 2 |
| 3 | 4 | 1 |
| 5 | 6 | 1 |
7. 当往`map`中插入数值时,若已存在(即`value2`的值为 `>=1` 的数值)便将总数`sum`加上`value2`的值,再将value2的值`+1`
8. 若不存在,则创建,并将value2的值初始化为`1`


## 代码（Java)
```java
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
    	//初始化Map集合
        HashMap<Integer, HashMap<Integer, Integer>> map = new HashMap<>();
		//定义总数sum，并初始化为0
        int sum = 0;
		//循环遍历二维数组dominoes
        for (int i = 0; i < dominoes.length ; i++)  {
            //获取当前「数字对」的值，并将较小的值设置为a,较大的值设置为b 
            Integer a = dominoes[i][0];
            Integer b = dominoes[i][1];
            if (a > b) {
                a = dominoes[i][1];
                b = dominoes[i][0];
            }
            //将a 作为Map1的key1
            //而b 作为Map1的value1 （即map2) 的key2

			//判断Map1中是否有key1 为 a 的值
            if (map.containsKey(a)) {
                HashMap<Integer, Integer> list = map.get(a);
                //判断Map2中是否有key2 为 b 的值
                if (list.containsKey(b)) {
                	//获取value2的值并加入到sum中
                    int count = list.get(b);
                    sum = sum + count;
                    //对应的value的值+1
                    list.put(b, count+1);
                    map.put(a, list);

                } else {
                	//初始化数值为1
                    list.put(b, 1);
                    map.put(a, list);
                }
            } else {
                //初始化数值为1
                HashMap<Integer, Integer> list = new HashMap<>();
                list.put(b, 1);
                map.put(a, list);
            }
        }
        return sum;
    }
}
```
