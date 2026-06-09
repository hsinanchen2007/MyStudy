```
int compare(string& s1, string& s2){
        int val1 = stoi(s1);
        int val2 = stoi(s2);
        if(val1 == val2) return 0;
        else if(val1 > val2) return 1;
        else return -1;
    }
    
    int compareVersion(string version1, string version2) {
        vector<string> v1;
        vector<string> v2;
        processString(version1,v1);
        processString(version2,v2);
        int curr = 0;
        while(curr < v1.size() && curr < v2.size()){
            if(compare(v1[curr], v2[curr]) == 1) return 1;
            else if(compare(v1[curr], v2[curr]) == -1) return -1;
            ++curr;
        }
        string zero("0");
        if(curr == v1.size() && curr == v2.size()) return 0;
        else if(curr == v1.size()){
            while(curr < v2.size()){
                if(compare(v2[curr++], zero) == 1) return -1;
            }
        }
        else{
            while(curr < v1.size()){
                if(compare(v1[curr++], zero) == 1) return 1;
            }
        }
        return 0;
    }
    
    void processString(string& version, vector<string>& v){
        int head = 0; string temp;
        while(head<version.size()){
            if(head == (int)version.size() - 1){
                temp.push_back(version[head]);
                v.push_back(temp);
                temp.clear();
            }
            else if(version[head] != '.'){
                temp += version[head];
            }
            else{
                v.push_back(temp);
                temp.clear();
            }
            ++head;
        }
    }
```