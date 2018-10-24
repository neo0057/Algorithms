"""
This is the edit distance module.

The example module supplies one function, getEditDistance(str1, str2); which calculates the operation count required to convert str1 to str2. An operation is defined as an insertion, deletion or replacement of one character.


For example,

>>> getEditDistance("cut","cat")
1
"""

def getEditDistance(str1, str2):
	"""Return the edit distance between two strings.
    
    >>> getEditDistance("abc", "abcd")
    1
    >>> getEditDistance("abc", "aacd")
    2
    
    If one of the strings is empty, it will return the length of the other string
    
    >>> getEditDistance("abc", "")
    3
    
    The order of strings is not important, it will return the same output when strings are swapped.

    >>> getEditDistance("rice", "raise")
    2
    >>> getEditDistance("raise", "rice")
    2
    """
    
    # if one of the strings is empty, the edit distance equals to the length of the other string
    # as all we need to do is insert all the characters from one string to other
	if len(str1)==0:
		return len(str2)
	if len(str2)==0:
		return len(str1)
	
    # neither one is empty
    # we will use wagner-fischer algorithm
    
    # matrix is one character bigger for each string, because we will start from 0
    # matrix[y+1][x+1] will hold the Levenshtein distance between first y chars of str1
    # and the first x chars of str2
	matrix = [ [i for k in range(len(str2)+1)] for i in range(len(str1)+1)]
    
    # we want to start by putting the numbers 0 to length of the string in the first column and row
	for i in range(len(str2)+1):
		matrix[0][i]=i
	# as the difference between any string and an empty string is the length of that string,
    # we start from 0 (no difference between two empty strings) and go up to its length
	
	for i in range(len(str2)):
    # now that we completed the first row and column of our matrix,
    # proceed to process the rest
		for j in range(len(str1)):
			if str2[i] == str1[j]:
				matrix[j+1][i+1] = matrix[j][i] # no difference in this character, edit distance will equal to previous
			else:
                # this char is different, get the lowest edit distance to acquire the previous string and add one
				matrix[j+1][i+1] = min(matrix[j][i+1]+1,matrix[j+1][i]+1,matrix[j][i]+1)
    # as stated earlier, matrix[y+1][x+1] will hold the Levenshtein distance between first y chars of str1
    # and the first x chars of str2. So the latest cell will hold the final edit distance
	return matrix[-1][-1]

if __name__ == "__main__":
    import doctest
    doctest.testmod()

