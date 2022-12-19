```
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        
        for(int i=left; i<=right; i++){
            int a = i;
            int b = i;
            int k = i;
            int c;
            bool flag = true;
            int count = 0;//位数
            
            while(k!=0){ //计算每一个数字i的位数count
                k=k/10;
                count++;
            }
   
            for(int j=1; j<=count; j++){ //将数字i拆分 并判断每一位是否能被i整除
                c=a%10;
                if(c!=0 && b%c != 0 || c==0){
                    flag = false;
                    break;
                }
                a=a/10;
            }
            if(flag==true)
                result.push_back(b);
        }
        return result;
    }
};
```

修改了一下 更加简单了一些
将每个i拆分开不需要计算i的位数
```
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i=left; i<=right; i++){
            bool flag = true;
            int a = i;
            while(a){
                int b=a%10;
                if((b!=0 && i%b!=0) || b==0){
                    flag = false;
                    break;
                }
                a=a/10;
            }
            if(flag)
                result.push_back(i);
        }
        return result;
    }
};
```
