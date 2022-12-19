```c++
class Solution {
public:
    int fib(int N) {
        int fa = 0;
        int fb = 1;
        if(N<=1)
            return N;
        int temp = 0;
        for(int i=2; i<=N; i++){
            temp = fa+fb;
            fa = fb; 
            fb = temp;
        }
        return fb;
    }
};