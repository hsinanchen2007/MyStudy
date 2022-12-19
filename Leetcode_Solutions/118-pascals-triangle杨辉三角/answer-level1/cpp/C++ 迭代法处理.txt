每行首尾都是1，可以先初始化每行全为1，再通过计算修改
```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
  	//先定义一个空数组，用来存放杨辉三角的每一行——小数组
        vector<vector<int>> res;
	//前两行是默认的数组
	if(numRows<=2){
		for(int i=0;i<numRows;i++){
			vector<int> small(i+1,1);//第1行有1个1，第二行有2个1
			res.push_back(small);//将前两行存入到res空数组中
		}
		return res;//res包含了杨辉三角的前两行
	}
	else{
		res = generate(numRows-1);//得到前numRows-1行的res数组
		vector<int> newsmall(numRows,1);//初始化第numsRow行
		//由第numRows-1行计算得到第numRows行，第numRows-1行在res数组中的索引为numRows-2
		for(int j=0;j<res[numRows-2].size()-1;j++){
			newsmall[j+1] = res[numRows-2][j] + res[numRows-2][j+1];
		}
		res.push_back(newsmall);
	}
	return res;
    }
};
```