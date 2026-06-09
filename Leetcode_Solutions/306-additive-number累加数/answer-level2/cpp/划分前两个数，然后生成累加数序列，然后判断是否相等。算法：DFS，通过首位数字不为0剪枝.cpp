template<class T>
string Fibonacci(T n1,T n2,int len){
   string ans = to_string(n1) + to_string(n2);
	T temp;
	while (ans.size() < len)
	{
		ans += to_string(n1+n2);
		temp = n1;
		n1 = n2;

		n2 = n2 + temp;
	}
	//ans = ans.substr(0, len);

	return ans;
}
class Solution {
public:
![QQ截图20190823160559.png](https://pic.leetcode-cn.com/5e93aef437041036368f36d7721bdb372694bffa55f963d4a7c5a2711e195ff1-QQ%E6%88%AA%E5%9B%BE20190823160559.png)
    bool isAdditiveNumber(string num) {
        if(num.size()<3)
          return false;
        unsigned long long num1,num2;
        for(int j = 1; j < num.size()/2+1;j++)
        {
        for(int i = 1; i+j+max(i,j)<=num.size();i++)
        {
            if(num.substr(0,j)[0]==0||num.substr(j,i)[0]==0)
              break;
            num1 = stoull(num.substr(0,j));
            num2 = stoull(num.substr(j,i));
            string  ans = Fibonacci( num1, num2,num.size());
            if(ans == num)
                return true;
        }
    
        }
         return false;        
    }
    
};