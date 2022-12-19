    class DinnerPlates {
        vector<int> buf;
        int k;
        vector<int> cnt;
        priority_queue<int,vector<int>,greater<int>> pql;
        priority_queue<int,vector<int>,less<int>> pqr;
    public:
        DinnerPlates(int capacity) {
            k = capacity;
        }
        
        void push(int val) {
            int i;
            while(pql.size()>0&&cnt[pql.top()]>=k)
            {
                pql.pop();
            }
            if(pql.size()==0)
            {
                buf.push_back(val);
                cnt.push_back(1);
                pqr.push(cnt.size()-1);
                pql.push(cnt.size()-1);
            }else
            {
                i = pql.top();
                if((i*k+cnt[i])<buf.size())
                    buf[i*k+cnt[i]] = val;
                else
                    buf.push_back(val);
                cnt[i]++;
                pqr.push(i);
            }
        }
        
        int pop() {
            int i;
            while(pqr.size()>0&&cnt[pqr.top()]==0)
            {
                pqr.pop();
            }
            if(pqr.size()==0)
                return -1;
            i = pqr.top();
            pql.push(i);
            return buf[i*k+ --cnt[i]];
        }
        
        int popAtStack(int index) {
            if((index*k)>buf.size()||cnt[index]==0)
                return -1;
            pql.push(index);
            return buf[index*k+ --cnt[index]];
        }
    };

    /**
    * Your DinnerPlates object will be instantiated and called as such:
    * DinnerPlates* obj = new DinnerPlates(capacity);
    * obj->push(val);
    * int param_2 = obj->pop();
    * int param_3 = obj->popAtStack(index);
    */
