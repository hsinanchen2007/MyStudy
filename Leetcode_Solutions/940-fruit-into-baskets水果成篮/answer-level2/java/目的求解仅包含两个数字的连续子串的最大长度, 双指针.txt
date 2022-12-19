![2020012401.PNG](https://pic.leetcode-cn.com/23da6b219f3bd98e7e8e65e571320266e36275f47ea8b7aba15857c551bdadaf-2020012401.PNG)

### 解题思路
题目的本质是求解仅包含两种数字的连续子串的最大长度;
声明max记录当前遇到的最大子串长度;
声明firstNum记录每个子串中的第一个数字,firstIndex记录第一个数字当前的索引值;
声明secondNum记录每个子串中的第二个数字,secondIndex记录第二个数字当前的索引值;
声明cnt记录当前子串的长度;
每当遇到第三个数字时,先判断当前cnt与max的大小,将两者较大值赋予max;
再更新cnt,更新cnt原则:
-------------1)记当前的索引为i，若tree[i-1]==fisrtNum时, cnt = i-secondIndex;
-------------2)若tree[i-1]==secondNum时, cnt = i-firstIndex;
同时更新firstNum和secondNum:
-------------1)firstNnum = tree[i-1],firstIndex=i-1;
-------------2)secondNum=tree[i],secondIndex=i;
遍历完整数数组tree后,返回max即可.

### 代码

```java
class Solution {
    public int totalFruit(int[] tree) {
    	int firstIndex = 0;
    	int firstNum = tree[0];//初始化第一个数字
    	int secondNum = -1;
    	int cnt =0;
    	int max = 0;
    	int i=0;
    	int secondIndex =0;
    	while(i<tree.length) {
    		if(tree[i]==firstNum) {
    			firstIndex = i;
    			cnt++;
    		}else if((tree[i]!=firstNum&&secondNum<0)) {//初始化第二个数字
    			cnt++;
    			secondIndex= i;
    			secondNum=tree[i];
    		}else if(tree[i]==secondNum&&secondNum>=0){
    			cnt++;
    			secondIndex= i;
    		}else if(tree[i]!=firstNum&&tree[i]!=secondNum&&secondNum>=0) {
    			if(cnt>max) {
    				max=cnt;
    			}
    			if(tree[i-1]==firstNum) {
    				cnt = (i-secondIndex);
    			}else if(tree[i-1]==secondNum) {
    				cnt = (i-firstIndex);
    			}
    			firstIndex = i-1;
    			firstNum = tree[firstIndex];
    			secondIndex = i;
    			secondNum = tree[secondIndex];
    		}
    		i++;
    	}
    	if(cnt>max) {
    		max=cnt;
    	}
        return max;
    }
}
```