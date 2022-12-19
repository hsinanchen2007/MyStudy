由题目可得，为了使己方得到胜利，在使用权力的时候需要把敌方淘汰了，所以成员执行权力的先后顺序决定着输赢。就比如DDRRR，虽然R方人比较多，但是D方先使用权力，最后胜利的D方的。
在解决这道题的时候有一个小技巧，就是当遍历到`R`的时候，不要马上去找`D`把它淘汰掉，而是用一个变量记着，等遍历到`D`的时候再把它淘汰掉。

```
class Solution {
    public String predictPartyVictory(String senate) {
    	
        boolean R = true, D = true;
        char[] arr = senate.toCharArray();
        
//      标记变量，当person > 0的时候，此时R方有权利把D方的成员淘汰掉
//      当person < 0的时候，D方有权利把R方的成员淘汰掉
        int person = 0;
        while(R && D) {
        	
//        	当遇到双方成员的时候置为true，表示当前还有人员存在
//        	当R或D为false，表示一方已经没有成员存在了，胜负已分，结束循环
        	R = false; D = false;
        	
        	for(int i = 0; i < arr.length; ++i) {
        		if(arr[i] == 'R') {
        			R = true;
        			if(person < 0) arr[i] = 'O';
        			++person;
        		}
        		else if(arr[i] == 'D') {
        			D = true;
        			if(person > 0) arr[i] = 'O';
        			--person;
        		}
        	}
        }
        return person > 0 ? "Radiant" : "Dire";
    }
}
```
