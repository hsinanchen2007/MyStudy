### 解题思路
其实思路很简单,就是通过两个队列来模拟

- 让一个队列指针s指向的队列始终作为栈顶的部分进行插入,以及求top()
- 然后如果要pop(),那么我们就把队列指针s指向的队列的值放到队列指针f指向的队列,然后最后交换队列指针,达到始终有s是栈顶的操作,这里是值的移动是最消耗时间的,需要O(n)
- 然后由上面可以知道,我们的Stack有值的时候,队列指针s指向的队列一定会有值,因为pop之后还是让s当做栈顶,栈顶有就Stack有,所以empty也就很明显是s->empty()



### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        f = &a;
        s = &b;
    }

    /** Push element x onto stack. */
    void push(int x) {
        s->push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // if(empty()) throw error;
        while(s->size()>1){
            f->push(s->front());
            s->pop();
        }
        int ans = s->front();
        s->pop();
        swap(f,s);
        return ans;
    }

    /** Get the top element. */
    int top() {
        // // if(empty()) throw error;
        // while(s->size()>1){
        //     f->push(s->front());
        //     s->pop();
        // }
        // int ans = s->front();
        // f->push(ans);
        // s->pop();
        // swap(f,s);
        // return ans;
        return s->back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return s->empty();
    }
private:
    queue<int> a,b;
    queue<int> * f;
    queue<int> * s;
};
```


### 完整含测试的代码
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        f = &a;
        s = &b;
    }

    /** Push element x onto stack. */
    void push(int x) {
        s->push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // if(empty()) throw error;
        while(s->size()>1){
            f->push(s->front());
            s->pop();
        }
        int ans = s->front();
        s->pop();
        swap(f,s);
        return ans;
    }

    /** Get the top element. */
    int top() {
        // // if(empty()) throw error;
        // while(s->size()>1){
        //     f->push(s->front());
        //     s->pop();
        // }
        // int ans = s->front();
        // f->push(ans);
        // s->pop();
        // swap(f,s);
        // return ans;
        return s->back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return s->empty();
    }
private:
    queue<int> a,b;
    queue<int> * f;
    queue<int> * s;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    int param_1 = obj->pop();
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    cout<<" parm1: "<< param_1 <<" parm2: "<< param_2 <<" parm3: "<<param_3<<" param_4: "<<param_4<<endl;

    return 0;
}
```