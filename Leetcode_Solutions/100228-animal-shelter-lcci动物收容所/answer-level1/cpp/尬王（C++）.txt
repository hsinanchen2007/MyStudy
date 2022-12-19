### 解题思路

执行用时 :116 ms, 在所有 C++ 提交中击败了100.00%的用户内存消耗 :68.6 M, 在所有 C++ 提交中击败了100.00%的用户,把vector放public中定义竟然时间会缩短，原来res(2)会报错，发现是由于在声明.h 文件中不能直接调用vector类的析构函数赋值，应先定义后resize。
### 代码

```cpp
class AnimalShelf {
    
    queue<int> cat;
    queue<int> dog;
    
public:
    
    vector<int> res;
    AnimalShelf() {
        
    }
    
    void enqueue(vector<int> animal) {
        if(animal[1]==0)
        {
            cat.push(animal[0]);
        }
        if(animal[1]==1)
        {
            dog.push(animal[0]);
        }
    }
    
    vector<int> dequeueAny() {
        res.resize(2);
        if(cat.empty()&&dog.empty())
        {
            res[0]=-1;
            res[1]=-1;
            return res;
        }
        if(cat.empty()&&!dog.empty())
        {
            res[0]=dog.front();
            dog.pop();
            res[1]=1;
            return res;
        }
        if(!cat.empty()&&dog.empty())
        {
            res[0]=cat.front();
            cat.pop();
            res[1]=0;
            return res;
        }
        
        if(!cat.empty()&&!dog.empty())
        {
            if(cat.front()<dog.front())
            {
                res[0]=cat.front();
                cat.pop();
                res[1]=0;
                return res;
            }
            else
            {
                res[0]=dog.front();
                dog.pop();
                res[1]=1;
                return res;
            }
        }
        return res;
    }
    
    vector<int> dequeueDog() {
        res.resize(2);
        if(!dog.empty())
        {
            res[0]=dog.front();
            dog.pop();
            res[1]=1;
            return res;
        }
        else
        {
            res[0]=-1;
            res[1]=-1;
            return res;
        }
    }
    
    vector<int> dequeueCat() {
        res.resize(2);
        if(!cat.empty())
        {
            res[0]=cat.front();
            cat.pop();
            res[1]=0;
            return res;
        }
        else
        {
            res[0]=-1;
            res[1]=-1;
            return res;
        }
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */
```