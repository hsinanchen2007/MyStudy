`swift 
          
    func strStr(_ haystack: String, _ needle: String) -> Int {
        if (needle.count > haystack.count ){ return -1 }
        if (needle.count == 0){ return 0 }
        let plainCount = haystack.count-needle.count
        for i in 0...plainCount {
            let sss = (haystack as NSString).substring(with: NSRange.init(location: i, length: needle.count))
            if(sss == needle) {
                return i
            }
        }
        return -1
    }`