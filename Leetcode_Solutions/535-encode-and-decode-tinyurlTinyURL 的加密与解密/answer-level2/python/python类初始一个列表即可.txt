class Codec:
    def __init__(self):
        self.p=[]
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        self.p.append(longUrl[len(longUrl)-1])
        return longUrl[0:len(longUrl)-1]

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return shortUrl+self.p.pop()