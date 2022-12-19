### 代码

```cpp
class Solution {
public:
	int isRight(int x,int y){
		if(x%y==0&&0<y&&y<x)return x-y;
		else return -1;
	}
    bool divisorGame(int N) {
		int flag=-1;
		while(true){
			for(int i=1;i<=N;++i){
				if(i==N){
					return flag==-1?false:true;
				}
				if(isRight(N,i)!=-1){
					flag*=-1;
					N-=i;
					break;
				}
			}
		}
		return false;
    }
};
```