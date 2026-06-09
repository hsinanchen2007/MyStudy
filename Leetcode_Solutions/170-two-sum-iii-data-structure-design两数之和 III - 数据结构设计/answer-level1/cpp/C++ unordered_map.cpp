方法1、 使用hash表，key为数字，value为数字出现次数  //注意：可能存在添加多个相同元素 测试用例即有add多个相同元素

    class TwoSum {
    public:
        /** Initialize your data structure here. */
        TwoSum() {
            m_hash.reserve(4*1024);
        }

        /** Add the number to an internal data structure.. */
        void add(int number) {
            ++m_hash[number];
        }

        /** Find if there exists any pair of numbers which sum is equal to the value. */
        bool find(int value) {
            for (auto iter = m_hash.begin(); iter != m_hash.end(); ++iter)
            {
                auto found = m_hash.find(value - iter->first);
                if (found != m_hash.end())
                {
                    if(found->first != iter->first || (found->first == iter->first && found->second > 1))
                        return true;
                }
            }
            return false;
        }

    private:
        unordered_map<int, int> m_hash;
    };