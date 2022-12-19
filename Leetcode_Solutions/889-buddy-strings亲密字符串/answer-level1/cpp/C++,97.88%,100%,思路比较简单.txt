分为AB相等和不等来处理

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length()!=B.length())
        return false;
        map<char,int> a;
        int i=0,j=A.length()-1;
        if(A==B){
            //只要有某个字符出现两次就够了
            for(int i=0;i<A.length();i++){
                char tt=A[i];
                a[tt]++;
                if(a[tt]>1)
                return true;
            }
            return false;
        }
        //处理AB不等的情况
        else{
            while(i<j){
                if(A[i]==B[i])
                i++;
                else if(A[j]==B[j])
                j--;
                else
                break;
            }
            if(i==j)
            return false;
            else{
                char temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
            if(A==B)
            return true;
            else
            return false;
        }
    }
};