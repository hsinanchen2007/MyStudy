![360截图20200406133219354.jpg](https://pic.leetcode-cn.com/d6fd43248cc616402386788388a66037943caadad9f8f9d34604f7bc860d8c9c-360%E6%88%AA%E5%9B%BE20200406133219354.jpg)

 bool uniqueOccurrences(vector<int>& arr) {
        //vector<int> a(10000,0);
        sort(arr.begin(),arr.end());
        unordered_set<int> a;
        int i = 0,j=0;
        while(i<=j && j<arr.size()) { // i=3 j=3
            int times=0;
            while(j<arr.size() && arr[i] == arr[j]) j++;
            times = j-i; // times=3 2
            //if(j== arr.size()) times = j-i +1;
            if(a.find(times) != a.end()) 
                return false;
            a.insert(times); // a=3 2
            i=j;
        }
        return true;
        

    }