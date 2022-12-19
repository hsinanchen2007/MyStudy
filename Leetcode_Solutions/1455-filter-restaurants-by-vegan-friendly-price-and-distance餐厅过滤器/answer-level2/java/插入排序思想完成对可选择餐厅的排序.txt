![2020040801.PNG](https://pic.leetcode-cn.com/6e9cfa940a4cd6825db80973f4e256f1b3497edb5db140c2064744329051a0b6-2020040801.PNG)
### 解题思路
刚从另一道题跳过来,
被另一道题虐惨了, 
思路:
0) 声明out 记录输出结果

1) 声明数组id, 记录符合条件的餐厅的id;

2) 声明数组rate, 记录符合条件的餐厅的rating;

3) 声明变量index, 变量index是数组id和rate 的索引;

4) 遍历一遍数组, 将符合条件的餐厅的id和Rating记录下来

5) 声明sortRate数组, 通过插入排序将rate数组中的rating值排序, 同时将排序后的rating值在rate数组中的下标依次记录在sortRate数组中

6) 遍历一遍数组sortRate, 将sortRate[i]索引对应到数组id的数值依次添加到out中

7) 返回out
### 代码

```java
class Solution {
    public List<Integer> filterRestaurants(int[][] restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        List<Integer> out = new ArrayList<>();//记录输出结果
    	int[] id = new int[restaurants.length];//记录符合条件的餐厅的id
    	int[] rate = new int[restaurants.length];//记录符合条件的餐厅的rating
    	int index = 0;//变量index是数组id和rate 的索引
        //筛选出符合条件的餐厅
    	for(int i=0;i<restaurants.length;i++) {
    		if(veganFriendly==1) {
    			if((restaurants[i][2]==1)&&(restaurants[i][3]<=maxPrice)&&(restaurants[i][4]<=maxDistance)) {
    				id[index] = restaurants[i][0];
    				rate[index] = restaurants[i][1];
    				index++;
    			}
    		}else{
    			if((restaurants[i][3]<=maxPrice)&&(restaurants[i][4]<=maxDistance)) {
    				id[index] = restaurants[i][0];
    				rate[index] = restaurants[i][1];
    				index++;
    			}
			}
    	}
    	int[] sortRate = new int[index];//记录索引
        //插入排序思想实现将数组rate中的数值按照从大到小排序, 
        //用数组sortRate 记录排序后的数值在rate数组中对应的索引值, 也就是sortRate仅仅记录数值在rate中的索引下标
        //sortRate仅仅记录索引下标(索引下标, 是指排序前的数字在数组rate中的索引值)
		for (int i = 1; i < index; i++) {
			int j = i;
			while (j - 1 >= 0 && rate[i] >= rate[sortRate[j - 1]]) {
				sortRate[j] = sortRate[j - 1];
				j--;
			}
			if ((j+1)<index&&rate[i] == rate[sortRate[j + 1]]) {//当两个餐厅的rating 一样时, 按照id的大小来将两个rating排序
				if (id[i] < id[sortRate[j + 1]]) {
					sortRate[j] = sortRate[j + 1];
					sortRate[j + 1] = i;
				} else {
					sortRate[j] = i;
				}
			} else {
				sortRate[j] = i;
			}
		}
        //排序完成后, 得到数组sortRate, sortRate中的值, 是rating按照从大到小排序后的数值在rate数组中对应的索引值,
        //遍历数组sortRate, 依次将餐厅的id添加到out中
		for(int i=0;i<index;i++) {
			out.add(id[sortRate[i]]);
		}
    	return out;
    }
}
```