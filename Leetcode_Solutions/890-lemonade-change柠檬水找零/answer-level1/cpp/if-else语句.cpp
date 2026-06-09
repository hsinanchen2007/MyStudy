![image.png](https://pic.leetcode-cn.com/68db623021df73ce239e3d44f9ae37a93f068bc31e02dd94162f43e43d159749-image.png)

```
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twelve=0;
        //分别表示5、10、20面值的纸币个数
		int i;
		for(i=0;i<bills.size();i++){
			if(bills[i]==5)
				five++;
			else if(bills[i]==10){
				if(five>0){
					five--;
					ten++;
				}
				else
					return 0;
			}
			else if(bills[i]==20){
				if(ten>0){//找1个5，1个10 
					if(five>0){
						ten--;
						five--;
						twelve++;
					}
					else
						return 0;
				}
				else{//找3个5 
					if(five>=3){
						five-=3;
						twelve++;
					}
					else
						return 0;
				} 
			}
		}
		return 1;
    }
};
```
