class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int num_b = 0;
        int num_a = 0;
        int num_l = 0;
        int num_o = 0;
        int num_n = 0;

        for(int i =0 ; i<text.size(); i++)
        {
            switch(text[i])
            {
                case'b':
                num_b++;break;
                
                case'a':
                num_a++;break;

                case'l':
                num_l++;break;

                case'o':
                num_o++;break;

                case'n':
                num_n++;break;

                default:
                break;
            }
        }
    int a[5] = {num_o/2,num_n,num_l/2,num_b,num_a};
    int sum =100000;
    for(int i = 0; i<5 ; i++)
    {
        if(a[i]<sum) sum = a[i];
    }
    return sum;
    }
};