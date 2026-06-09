```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0)
            return false;

        vector<int> v;

        while (x)
        {
            v.push_back(x % 10);
            x /= 10;
        }

        for (int i = 0; i < v.size() / 2; ++i)
        {
            if(v.at(i) != v.at(v.size() - 1 - i))
            {
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(int x) {
        
        if (x < 0)
            return false;

        //先获取数字位数
        int div = 1;
        int size = 1;
        while (x / div >= 10)
        {
            ++size;
            div *= 10;
        }

        vector<int> v(size); //避免数组扩容
        int i = 0;

        while (x)
        {
            v.at(i++) = x % 10;
            x /= 10;
        };

        for (int i = 0; i < v.size() / 2; ++i)
        {
            if (v.at(i) != v.at(v.size() - 1 - i))
            {
                return false;
            }
        }
        return true;
    }


    bool isPalindrome(int x) {

        if (x < 0)
            return false;

        int div = 1;

        while (x / div >= 10)
            div *= 10;

        while (x)
        {
            int left = x / div;
            int right = x % 10;
            
            if (left != right)
                return false;

            x -= left * div;
            x /= 10;
            div /= 100;
        }

        return true;
    }


    bool isPalindrome(int x) {

        if (x < 0 || (x != 0 && x % 10 == 0)) // 必须有(x != 0 && x % 10 == 0) 这个条件先过滤末尾为0的数字，这种数字后续反转比较会出问题
            return false;

        int num = 0; //后半段数字的反转数字

        while (x > num)
        {
            num = num * 10 + x % 10;
            x /= 10;
        }
        
        return x == num || x == num / 10;
    }
};