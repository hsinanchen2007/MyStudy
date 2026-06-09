![2019122302.PNG](https://pic.leetcode-cn.com/43a6e7d0cd3baafa4c2f2d5a82ce23f69f7059cb6c2b1ab6fd3c4904f5d1a279-2019122302.PNG)
### 解题思路
首先,将text切割成String[] myString数组,再遍历一遍数组myString,
遍历过程中分别将myString[i]与first比较,以及将myString[i+1]与second比较,
若两个比较同时相等,则记录myString[i+2]字符串(字符串的记录用ArrayList完成),
最后用一个for循环将ArrayList转换成Array,
### 代码

```java
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        //########耗时1ms
        String[] myString = new String[text.length()];
        ArrayList<String> a = new ArrayList<String>();
        myString = text.split(" ");
        for(int i=0;i<myString.length-2;i++) {
        	if(myString[i].equals(first)&&myString[i+1].equals(second)) {
        		a.add(myString[i+2]);
        	}
        }
        String[] result = new String[a.size()];
        for(int i = 0;i<a.size();i++) {
        	result[i] = a.get(i);
        }
        return result;
        //#############耗时1ms
        String[] myString = new String[text.length()];
        String[] result = new String[text.length()];
        int count=0;
        myString = text.split(" ");
        for(int i=0;i<myString.length-2;i++) {
        	if(myString[i].equals(first)&&myString[i+1].equals(second)) {
        		result[count] = myString[i+2];
        		count++;
        	}
        }
        String[] finalRes = new String[count];
        System.arraycopy(result, 0, finalRes, 0, count);
        return finalRes;
    }
}
```