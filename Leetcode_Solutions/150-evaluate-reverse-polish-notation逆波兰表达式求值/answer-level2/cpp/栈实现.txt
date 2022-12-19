    void calc(string str, vector<int> &nums)
    {
        bool isOp = false;
        if(!strcmp(str.c_str(),"+") || !strcmp(str.c_str(), "-") || !strcmp(str.c_str(), "*") || !strcmp(str.c_str(), "/"))
        {
            isOp = true;
        }
        
        if(false == isOp)
        {
            int num = atoi(str.c_str());
            nums.push_back(num);

        }
        else{
            int num2 = *(nums.end()-1);
            nums.pop_back();
            int num1 = *(nums.end()-1);
            nums.pop_back();
            if(!strcmp(str.c_str(),"+"))
            {
                nums.push_back(num1+num2);
            }
            else if(!strcmp(str.c_str(),"-"))
            {
                nums.push_back(num1-num2);
            }
            else if(!strcmp(str.c_str(), "*"))
            {
                nums.push_back(num1*num2);
            }
            else
            {
                nums.push_back(num1/num2);
            }   
        }
        return ;

    }
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        for(auto val: tokens)
        {
            calc(val, nums); 
            // cout << nums[nums.size()-1] << endl;
        }
        
        return nums[0];
    }