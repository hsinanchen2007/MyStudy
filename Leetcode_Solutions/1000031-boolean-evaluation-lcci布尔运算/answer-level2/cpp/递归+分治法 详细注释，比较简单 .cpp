首先我们应该清楚一件事情。就是想让形如 "表达式 运算符 表达式 = result" 这种情况共有多少种,这种问题，我们应该怎么分解呢？我们假设 表达式类似于s = "0&0&0&1^1|0" == result 如题干所述。 那么仔细观察这个表达式,对于任何一个运算符，他都可以按照表达式中运算符的位置拆分成一个子问题，我们以中间的&（加粗）为例：
  0&0&0 **&** 1^1|0 == 1  ==>   0&0&0形成1的数量 （乘以） 1^1|0形成1的数量

在上面的表达式中我们仅仅以中间的& 为例。这意思就是，左边的以括号的形式括起来进行优先计算，右边的以括号括起来进行优先计算。两边计算完了，再最后计算中间&形成的表达式。那么对于任何一个运算符，都可以拆分成左右两个部分，进行计算结果，最后再把这些运算符左右结果相乘（相当于排列组合）然后再加和，就是总的排列顺序了。

这显然是分治的思想。事实上用分治+递归的想法解决此类排列问题非常有效。需要注意的是，要有一个数组进行记录之前递归计算过结果的部分，否则会超时。代码如下：
```
class Solution {
public:
	vector<char> vec;
	int ret = 0;
	int countEval(string s, int result) {
        //先把字符串转换成字符数组，方便之后计算
		for (int i = 0; i < s.size(); i++){
			vec.push_back(s[i]);
		}
		//分别存储结果是0,1的数量。比如v0[i][j]表示从索引i到j算出来结果是0的数量
		vector<vector<int>> v0(s.size(), vector<int>(s.size(), -1));
		vector<vector<int>> v1(s.size(), vector<int>(s.size(), -1));

		return helper(vec, 0, vec.size() - 1, result, v0, v1);
	}
	//从start到end（包含）形成结果为result的种类数
	int helper(vector<char> &vec, int start, int end, int result, vector<vector<int>> &v0, vector<vector<int>> &v1){
		if (start == end){//边界条件，因为只有一个字符，所以这个字符必须等于result才可以
			int rec = int(vec[start] - '0');
			return rec == result ? 1 : 0;
		}
        //避免重复计算
		if (result == 0 && v0[start][end] != -1) return v0[start][end];
		if (result == 1 && v1[start][end] != -1) return v1[start][end];

		int sum = 0;
        //计算每一个& | ^左右两边的所有可能情况。左右的所有可能情况相乘，然后再求和就是结果
		for (int i = start + 1; i <= end - 1; i += 2){
			switch (vec[i])
			{
			case '&':
				if (result == 0){ //result == 0 对应 0 & 0， 0 & 1， 1 & 0
					sum += helper(vec, start, i - 1, 0, v0, v1) * helper(vec, i + 1, end, 0, v0, v1);
					sum += helper(vec, start, i - 1, 0, v0, v1) * helper(vec, i + 1, end, 1, v0, v1);
					sum += helper(vec, start, i - 1, 1, v0, v1) * helper(vec, i + 1, end, 0, v0, v1);
				}
				else{//result == 1，对应 1 & 1
					sum += helper(vec, start, i - 1, 1, v0, v1) * helper(vec, i + 1, end, 1, v0, v1);
				}
				break;
			case '|':
				if (result == 0){//result == 0 对应 0 | 0
					sum += helper(vec, start, i - 1, 0, v0, v1) * helper(vec, i + 1, end, 0, v0, v1);
				}
				else{//result == 1,对应 0 | 1， 1 | 0， 1 | 1
					sum += helper(vec, start, i - 1, 0, v0, v1) * helper(vec, i + 1, end, 1, v0, v1);
					sum += helper(vec, start, i - 1, 1, v0, v1) * helper(vec, i + 1, end, 0, v0, v1);
					sum += helper(vec, start, i - 1, 1, v0, v1) * helper(vec, i + 1, end, 1, v0, v1);
				}
				break;
			case '^':
				if (result == 0){// 0 ^ 0, 1 ^ 1
					sum += helper(vec, start, i - 1, 0, v0, v1) * helper(vec, i + 1, end, 0, v0, v1);
					sum += helper(vec, start, i - 1, 1, v0, v1) * helper(vec, i + 1, end, 1, v0, v1);
				}
				else{//result == 1, 1 ^ 0, 0 ^ 1
					sum += helper(vec, start, i - 1, 0, v0, v1) * helper(vec, i + 1, end, 1, v0, v1);
					sum += helper(vec, start, i - 1, 1, v0, v1) * helper(vec, i + 1, end, 0, v0, v1);
				}
				break;
			default:
				break;
			}
		}

		if (result == 0){
			v0[start][end] = sum;
			return v0[start][end];
		}
		else{
			v1[start][end] = sum;
			return v1[start][end];
		}
	}
};

```
