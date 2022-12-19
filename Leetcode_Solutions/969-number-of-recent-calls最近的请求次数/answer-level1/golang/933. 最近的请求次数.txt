type RecentCounter struct {      
    recent *list.List 
}  
func Constructor() RecentCounter { 
    return RecentCounter{        
        recent : list.New(),    
    }  
}   

func (this *RecentCounter) Ping(t int) int {    
    this.recent.PushBack(t) 
     for this.recent.Front().Value.(int) <(t-3000){         
         this.recent.Remove(this.recent.Front())   
    }    
    return this.recent.Len()    
}
