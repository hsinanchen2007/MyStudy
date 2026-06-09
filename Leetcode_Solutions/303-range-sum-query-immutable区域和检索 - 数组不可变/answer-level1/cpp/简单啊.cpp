这道题没什么意义啊，是我没理解到出题人的意图吗？```

1. class NumArray{
2. public:
3.      NumArray(vector<int>nums) {num=nums;}
4.      int sumRange(int i,int j)
5.          {
6.              int result=0;
7.              for(int k=i;k<=j;k++)
8.                  {
9.                      result+=num[k];
9.                  }
10.          return result; 
8.         }
9. private:
10.     vector<int> num; 
5. }

