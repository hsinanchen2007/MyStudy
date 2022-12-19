### 解题思路
我的思路很笨，就是直接找。先找到label所在的层数，看它与本层最小标号差几个节点（差为n1），将n1除以2既是label的父亲节点反向差几个节点（与对应层的最大值相比），之后再以新的label继续向上找。

### 代码

```cpp
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
   
	int dength=1;
	vector<int> a;
	
	if(label==1){
		a.insert(a.begin(),1);
		return a;
	}
	//确定层数 
	while(1){
		if(pow(2,dength-1)-1<label&&pow(2,dength)-1>=label){
			break;
		}
		dength++;
	}
	//cout<<"层数:"<<dength<<endl;
	int n1=0;
	int mylabel=label;
	while(mylabel>1){
          //关键就是这两个式子不好想
		  n1=(mylabel-pow(2,dength-1))/2;
		  mylabel=pow(2,dength-1-1)+(pow(2,dength-1-1)-n1-1);
		  a.insert(a.begin(),mylabel);
		  dength--; 
	}
	a.insert(a.end(),label);
//	for(int i=0;i<a.size();i++){
//		cout<<a[i]<<endl;
//	}
	


	return a;


    }
};
```