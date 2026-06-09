class Solution {
public:
    vector<int> closestDivisors(int num) {
        int max;
        for(int i = 1; i <= floor(sqrt(num + 2) + 0.5); i++)
        {
            if ((num + 1) % i == 0 or (num + 2) % i == 0 )
                max = i;
        }
        if ((num + 1) % max == 0)
            return {(num+1)/max,max};
        else
            return {(num+2)/max , max};
    }
};