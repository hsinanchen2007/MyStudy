```
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        
        map<string,int> domain;
        
        vector<string> output;    
        
        for(int i=0; i<cpdomains.size(); i++){
            
            size_t pos1 = cpdomains[i].find(" ");//找出空格的位置
            string temp = cpdomains[i].substr(0, pos1);//截取出表示访问次数的字符串
            
            int count = atoi(temp.c_str());//转为int
            
            if(pos1!=cpdomains[i].npos){

                string temp = cpdomains[i].substr(pos1+1,cpdomains[i].size()-1);//截取出最低一级的域名

                //output.push_back(temp);
                domain[temp] += count;//向map中插入最低一级的域名
                //cout << temp << endl;
            }
            
            
            size_t pos2 = cpdomains[i].find(".");//找出"."的位置
            
            while(pos2!=cpdomains[i].npos){
                
                string temp = cpdomains[i].substr(pos2+1,cpdomains[i].size()-1);//依次截取高级域名
                domain[temp] += count;//向map中插入域名
                
                pos2 = cpdomains[i].find(".", pos2+1);//查找下一个"."
                //cout << temp << endl;
            }
        }
        
        map<string,int>::iterator it;
        
        for(it = domain.begin(); it!=domain.end(); it++){
            
            string temp = std::to_string(it->second) + " " + it->first;//注意将int转为string
            output.push_back(temp);
            
            //cout << it->first << ":" << it->second << endl;
        }
        
        //cout << domain.size() <<endl;

        
        return output;
        
        
    }
};
```
