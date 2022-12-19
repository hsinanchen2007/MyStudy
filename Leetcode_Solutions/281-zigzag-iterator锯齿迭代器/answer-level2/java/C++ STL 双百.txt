## 思路
设置一个 flag ，为真的时候返回 vector1 数据，为假的时候返回 vector2 的数据；
返回之前 flag 取反，返回之后迭代器自增

## 代码
```c++
class ZigzagIterator {
public:

    vector<int>::const_iterator m_iter1,m_iter2;
    vector<int>::const_iterator m_v1_cend,m_v2_cend;
    bool m_flag; //flag = true v1,   flag=false v2;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        m_v1_cend = v1.cend();
        m_v2_cend = v2.cend(); 
        m_iter1 = v1.cbegin();
        m_iter2 = v2.cbegin();
        m_flag = true;
    }

    int next() {
        bool prev = m_flag;
        m_flag = !m_flag;
        if(m_iter1!=m_v1_cend && m_iter2!=m_v2_cend){
            
            return prev? (*(m_iter1++)):(*(m_iter2++));
        }
        if(m_iter1==m_v1_cend)
            return *(m_iter2++);
        
        return *(m_iter1++);
    }

    bool hasNext() {
        return !(m_iter1==m_v1_cend && m_iter2==m_v2_cend);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */


```

## 提交记录

![image.png](https://pic.leetcode-cn.com/eb4666c3ec5c7ecf1d4c8da06ed43cf92c25cf61e25deedef3d07e69ae825423-image.png)

