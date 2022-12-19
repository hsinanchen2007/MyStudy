### 解题思路
此处撰写解题思路
1 <= n <= 10^9      行数
1 <= reservedSeats.length <= min(10*n, 10^4)    预约的最大数为10^4
reservedSeats[i].length == 2		一维数组长度为2
1 <= reservedSeats[i][0] <= n		一维数组下表取值 1~n
1 <= reservedSeats[i][1] <= 10		一维数组取值 1~10
所有 reservedSeats[i] 都是互不相同的。  保证每一位都是唯一的


使用hashmap原因是底层扩容，数组大小最大10^4 不会造成内存移除
第一位行数
用boolean数组纪律当前行的座位状态
之后就是遍历hashmap
针对与每一行进行一个状态判断

优化点：状态判断这里写的不怎么样，大家可以优化一下
结果：
执行用时：31ms
内存消耗：43.5MB
显示击败100%用户，(●'◡'●) 第一次，很激动，小小喧嚣一下，别喷我哈
掉的坑：刚开始没有仔细读题，没有仔细分析提示信息，思路是直接定义一个包含所有座位的boolean二维数据，导致初始在10亿大小时直接报内存溢出
```java
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
HashMap<Integer,boolean[]> temp = new HashMap<Integer,boolean[]>();
        for(int i=0; i<reservedSeats.length; i++) {
        	if(temp.containsKey(reservedSeats[i][0])) {
        		temp.get(reservedSeats[i][0])[reservedSeats[i][1]-1] = true;     
        	}else {
        		boolean[] b = new boolean[10];
        		b[reservedSeats[i][1]-1] = true;
        		temp.put(reservedSeats[i][0], b);        		
        	}
        }
        int max = n*2;
        for (Map.Entry<Integer, boolean[]> entry : temp.entrySet()) {
        	boolean[] zw = entry.getValue();
    		if(zw[2]&&zw[5]) {//不存在选四个人了
        		max = max - 2;
        	}else {
        		if(zw[3] || zw[4]) {
        			max = max -1;
        			if(zw[5]||zw[6]) {
        				max = max - 1;
        			}else if(zw[7]||zw[8]){
        				max = max - 1;
        			}
        		}else if(zw[5] || zw[6]) {
	        			max = max -1;
	        			if(zw[1]||zw[2]) {
	        				max = max - 1;
	        			}
	        		}else if(zw[1]|| zw[2]) {
	        			max = max - 1;
	        		} else if( zw[7]|| zw[8]) {
	        			max = max - 1;
	        		}
        	}
        }
        return max;
    }
}
```