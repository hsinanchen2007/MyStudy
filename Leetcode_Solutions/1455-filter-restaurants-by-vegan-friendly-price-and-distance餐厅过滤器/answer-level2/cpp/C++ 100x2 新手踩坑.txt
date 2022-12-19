排序就手写了个冒泡，没什么好说的。关键在于踩了一个坑：遍历数组时尽量不要写i<id.size();最好写成两步:int n=id.size();i<n，不然会报错。
当时写题的时候没用第二种写法，直接加了个if(id.size()>0)的判断。
```
 vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int n=restaurants.size();
        vector<int>id;
        vector<int>rating;
        for(int i=0;i<n;i++){
            if(veganFriendly==1){
                if(restaurants[i][2]==veganFriendly&&restaurants[i][3]<=maxPrice&&restaurants[i][4]<=maxDistance){
                   id.push_back(restaurants[i][0]);
                   rating.push_back(restaurants[i][1]);
                }
            }else{
                if(restaurants[i][3]<=maxPrice&&restaurants[i][4]<=maxDistance){
                   id.push_back(restaurants[i][0]);
                   rating.push_back(restaurants[i][1]);
                }
            }
            
        }
        int t=0,r=0;
        int m=id.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<m-i-1;j++){
                if(rating[j]<rating[j+1]){
                    t = rating[j];r=id[j];
                    rating[j]=rating[j+1];id[j]=id[j+1];
                    rating[j+1]=t;id[j+1]=r;
                }
                
            }
            
        } 
   
    if(id.size()>0)
    for(int j=0;j<id.size()-1;j++){
        cout<<"aaa"<<endl;
        if(rating[j]==rating[j+1]&&id[j]<id[j+1]){
                    t = rating[j];r=id[j];
                    rating[j]=rating[j+1];id[j]=id[j+1];
                    rating[j+1]=t;id[j+1]=r;
                    
        }    
    }
    
    return id;
}
```
