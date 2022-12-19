两种方法，方法1略快一点

```
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n=A.size();

        int target=A[0];
        int pick=0,rotate=0;
        bool flag=true;
        for(int i=0;i<n;++i)
        {
            if(A[i]==target)
            {
                if(B[i]!=target)
                {
                    ++pick;
                }
            }
            else
            {
                if(B[i]==target)
                {
                    ++rotate;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
        }

        if(flag)
        {
            return min(pick,rotate);
        }

        target=B[0];
        pick=0,rotate=0;
        flag=true;
        for(int i=0;i<n;++i)
        {
            if(B[i]==target)
            {
                if(A[i]!=target)
                {
                    ++pick;
                }
            }
            else
            {
                if(A[i]==target)
                {
                    ++rotate;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
        }

        if(flag)
        {
            return min(pick,rotate);
        }

        return -1;
    }
};
```
```
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n=A.size();

        vector<int> counter(7,0);

        for(int i=0;i<n;++i)
        {
            ++counter[A[i]];
            if(B[i]!=A[i])
            {
                ++counter[B[i]];
            }
        }

        int target=0;
        for(int i=1;i<7;++i)
        {
            if(counter[i]==n)
            {
                target=i;
                break;
            }
        }

        if(target)
        {
            int pick=0,rotate=0;
            for(int i=0;i<n;++i)
            {
                if(A[i]==target)
                {
                    if(B[i]!=target)
                    {
                        ++pick;
                    }
                }
                else
                {
                    if(B[i]==target)
                    {
                        ++rotate;
                    }
                }
            }
            return min(pick,rotate);
        }
        else
        {
            return -1;
        }
    }
};
```
