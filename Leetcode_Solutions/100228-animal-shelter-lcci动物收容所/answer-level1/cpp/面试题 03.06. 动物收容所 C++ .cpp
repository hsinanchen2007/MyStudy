### 解题思路

使用猫、狗两个队列

1、入队时 根据动物种类 分别入队
 
2、出队时 根据队列是否为空、 比较猫狗两个队首 动物编号的大小，小的先出

注意判空



### 代码

```cpp
class AnimalShelf {
public:
    AnimalShelf() {
    }

    void enqueue(vector<int> animal) {
        if (animal.at(1) == 0) //动物种类：猫
        {
            m_queue_cat.push(animal);
        }
        else
        {
            m_queue_dog.push(animal);
        }
    }

    vector<int> dequeueAny() {

        vector<int> animal;

        if (m_queue_cat.empty() && m_queue_dog.empty())
        {
            return vector<int>{-1, -1};
        }
        else if (!m_queue_cat.empty() && m_queue_dog.empty())
        {
            animal = m_queue_cat.front();
            m_queue_cat.pop();
        }
        else if (m_queue_cat.empty() && !m_queue_dog.empty())
        {
            animal = m_queue_dog.front();
            m_queue_dog.pop();
        }
        else
        {
            if (m_queue_cat.front().at(0) < m_queue_dog.front().at(0)) //动物编号：猫 < 狗 猫先出
            {
                animal = m_queue_cat.front();
                m_queue_cat.pop();
            }
            else
            {
                animal = m_queue_dog.front();
                m_queue_dog.pop();
            }
        }

        return animal;
    }

    vector<int> dequeueDog() {

        if (m_queue_dog.empty())
        {
            return vector<int>{-1, -1};
        }

        vector<int> dog = m_queue_dog.front();
        m_queue_dog.pop();
        return dog;
    }

    vector<int> dequeueCat() {

        if (m_queue_cat.empty())
        {
            return vector<int>{-1, -1};
        }

        vector<int> cat = m_queue_cat.front();
        m_queue_cat.pop();
        return cat;
    }

private:
    queue<vector<int>> m_queue_cat;
    queue<vector<int>> m_queue_dog;
};

```