### 解题思路
1、使用map 并对value进行排序

2、使用map 并使用最大堆

3、使用两个常量级数组 + lambda表达式

### 代码

```cpp

class Solution {
public:

    //1、使用map 并对value进行排序
    static bool value_compare(const pair<char, int>& p1, const pair<char, int>& p2)
    {
        return p1.second > p2.second;
    }

    string frequencySort(string s) {

        map<char, int> m;

        for(int i = 0;i < s.size(); ++i)
        {
            ++m[s.at(i)];
        }

        vector<pair<char, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), value_compare);

        string s1;
        s1.reserve(s.capacity());
        for(int i = 0; i < v.size(); ++i)
        {
            for(int j = 0; j < v.at(i).second; ++j)
                s1.push_back(v.at(i).first);
        }

        return s1;
    }


    template<typename T, typename U>
    struct value_less
    {
        bool operator()(const pair<T, U>& left, const pair<T, U>& right) const
        {
            return left.second < right.second;
        }
    };

    //2.1、map + 最大堆
    string frequencySort(string s) {

        map<char, int> m;

        for (int i = 0; i < s.size(); ++i)
        {
            ++m[s.at(i)];
        }

        priority_queue<pair<int, char>> queue; //使用默认的pair operator<() 比较 也满足题意

        for (auto iter = m.begin(); iter != m.end(); ++iter)
        {
            queue.push(pair<int, char>(iter->second, iter->first));
        }

        string s1;
        s1.reserve(s.capacity());
        while (!queue.empty())
        {
            for (int i = 0; i < queue.top().first; ++i)
            {
                s1.push_back(queue.top().second);
            }
            queue.pop();
        }

        return s1;
    }


    // 2.2 map + 最大堆 按value排序 自定义比较器
    string frequencySort(string s) {

        map<char, int> m;

        for (int i = 0; i < s.size(); ++i)
        {
            ++m[s.at(i)];
        }
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, value_less<char, int>> queue(m.begin(), m.end());

        string s1;
        s1.reserve(s.capacity());
        while (!queue.empty())
        {
            for (int i = 0; i < queue.top().second; ++i)
            {
                s1.push_back(queue.top().first);
            }

            queue.pop();
        }

        return s1;
    }

    //3、使用两个常量级数组 + lambda表达式（为了方便比较函数访问数组，否则要定义成静态或全局的）
    string frequencySort(string s) {

        vector<int> v(128);

        for (int i = 0; i < s.size(); ++i)
        {
            ++v[s.at(i)];
        }

        vector<char> v_char(128);
        for (int i = 0; i < v_char.size(); ++i)
        {
            v_char.at(i) = i;
        }

        //对字符数组 根据统计次数 从大到小排序  使用lambda表达式 按引用访问v
        sort(v_char.begin(), v_char.end(), 
            [&v](const char& c1, const char& c2) 
            {
                return v.at(c1) > v.at(c2);
            }
        );

        string s1;
        s1.reserve(s.capacity());
        for (int i = 0; i < v_char.size(); ++i)
        {
            if (v.at(v_char.at(i)) == 0) //次数为0 提前终止
                break;

            for (int j = 0; j < v.at(v_char.at(i)); ++j)
                s1.push_back(v_char.at(i));
        }

        return s1;
    }
};


```