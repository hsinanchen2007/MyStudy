### 解题思路
先找到首字母的最后位置，然后遍历该区间，挨个的找区间内元素的最后位置，并更新index，当index不再增加时查找结束

### 代码

```cpp
class Solution {
public:
    vector<int> partitionLabels(string S) {
    	vector<int> re;
	char ch;
	int start=0;//存新的区间开始的位置角标
	int index=0;//存新的区间结束的角标
	while(1){
		ch=S[start];
        //找到首字母的最后位置（倒向搜索的方法）
		for(int i=S.length()-1;i>=start;i--){
			if(S[i]==ch){
				index=i;
				break;
			}
		}
        //对start到index区间内的所有字母进行考察，找他们的最后位置，然后更新index
		for(int i=start;i<index;i++){
			for(int j=S.length()-1;j>=start;j--){
				if(S[j]==S[i]){
					if(j>index)index=j;
					break;
				}
			}
		}
        //找完之后把区间大小放入数组中
		re.insert(re.end(),index-start+1);
        //如果index是最后的元素，则跳出
		if(index==S.length()-1){
			break;
		}
        //将开始的位置变换为index之后的位置，在进行新的循环
		start=index+1;
		index=0;
		
	 }
     return re;

    }
};
```