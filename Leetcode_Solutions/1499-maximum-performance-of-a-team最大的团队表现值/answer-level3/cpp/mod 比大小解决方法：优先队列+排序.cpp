快排（efficiency从大到小排序）+优先队列（队列元素为speed的值，队列最多k个元素，满了之后，如果新元素比当前最小的元素小则把最小元素踢出队列）：
最后选择第i个人的最优解为：优先队列中所有元素的和*efficiency[i]。如果选择第i个人比当前找到的最优解还要好那么就替换当前最优解。

存在问题：答案需要mod 1000000007，如果储存的就是mod后的值，那么比大小就会出问题：1000000008%1000000007=1
                                如果中间不mod最后再mod，根据题目数据范围，最优解的最大值为max(n)*max(speed)*max(efficienvy)=10^18
                                超过了long long的范围，可能会造成溢出。
解决方法：我们将最优答案拆分成 speed,和efficiency两个值来储存，比较的时候我们这么想：
            我们想比较a*b是否大于c*d，我们可以通过移项把这个比大小变为判断a/c*(b/d)和1的大小关系，这样就解决了答案溢出的问题，我们在中间过程中不进行mod，等到最后输出的时候再进行mod，也解决了mod改变大小关系的问题。


class Solution {
public:
   void qsort(int x,int y,vector<int>& speed, vector<int>& efficiency){
       int a=x,b=y,c=efficiency[(a+b)/2],d;
       while(a<b){
           while (efficiency[a]>c) a++;
           while (efficiency[b]<c) b--;
           if (a<=b){
               d=efficiency[a];efficiency[a]=efficiency[b];efficiency[b]=d;
               d=speed[a];speed[a]=speed[b];speed[b]=d;
               a++;b--;
           }
       }
       if (a<y) qsort(a,y,speed,efficiency);
       if (x<b) qsort(x,b,speed,efficiency);
   }
  struct cmp {
    bool operator()(const int n1, const int n2) {
    return n1>n2;
  }
  };
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        qsort(0,n-1,speed,efficiency);
        int p=1000000007;
        int eff=0;
        long long sum=0;
        long long time=0;
        priority_queue<int,vector<int>,cmp >q;
        for (int i=0;i<n;i++) {
            if (q.size()<k) {
                q.push(speed[i]);sum=sum+speed[i];
                if (1.0*time/sum*(1.0*eff/efficiency[i])<1) {time=sum;eff=efficiency[i];}
                }
            else if (q.size()>=k&&q.top()<speed[i]){
                sum=sum-q.top()+speed[i];q.pop();q.push(speed[i]);
                if (1.0*time/sum*(1.0*eff/efficiency[i])<1) {time=sum;eff=efficiency[i];}
                }
        }
        sum=(time%p*eff%p)%p;
        return sum;
    }
};