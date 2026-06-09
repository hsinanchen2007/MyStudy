### 解题思路
思路为为每一个插入的元素，不管是重复还是不重复的，都生成一个ID（也就是所有元素（包含重复）的数目），再建立一个字典保存ID到真实数字的映射，在摇号时，我们直接在ID中抽取，因为一个数字可能对应多个ID，因此数字的重复越多，ID越多，抽中的概率也线性增加。

此处生成两个map：

m1记录一个数所有的ID（也可以想象成这个数的‘马甲‘，虽然马甲称呼不一样，但是其实代表同一个数），m2记录'马甲'们对应的真实数值。

例如：放入1，1，1，2时，1有3个马甲（马甲号：1，2，3），2有一个马甲（马甲号 4）

m1（记录一个数的马甲）:

1->1,2,3
2->4

m2(用来记录realID和真实数字的对应):

1->1
2->1
3->1
4->2

这样抽取时就能保证一个号越多越容易中了。

但是如何保证O（1）时间抽取呢？ 参考不允许重复的题目思路，在删除一个元素时，保证这个元素对应的ID位置被前一个插入的元素填充，再保证size--，这样能确保size里面的每一个数都有一个ID对应一个数值。

为什么使用双端队列而不使用栈呢？因为每次删除一个数时的确从尾端删除一个ID，同时这个ID也应该从m1原先对应的尾端删除，但是当把新的ID插入时，应该插入到前端，这样才能确保m1的ID队列不会保存超过SIZE的ID号（感兴趣的读者可以当成思考题）。

### 代码

```cpp
class RandomizedCollection{
    private:
        int size;
        unordered_map<int, deque<int>> m1;
        unordered_map<int, int> m2;
    public:
        RandomizedCollection(){
            srand(time(NULL));
            size = 0;
            m1.clear();
        }

        bool insert(int val){
            bool exist = m1.count(val);
            m1[val].push_back(++size);
            m2[size] = val;
            return !exist;
        }
        
        int getRandom(){
            if(m1.empty()) return -1;
            return m2[rand() % (size) + 1];
        }

        bool remove(int val){
            int dk = val;
            if(!m1.count(dk)) return false;
            deque<int> &dq = m1[dk];
            int de = dq.back();
            dq.pop_back();
            deque<int> &dq2 = m1[m2[size]];
            if(de == size){
                goto erase;
            }
            m2[de] = m2[size];
            dq2.pop_back();
            dq2.push_front(de);
        erase:
            m2.erase(size--);
            if(m1[dk].empty()) m1.erase(dk);
            return true;
        }

};

```