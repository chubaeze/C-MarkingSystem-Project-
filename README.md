Given an essay that has to be marked, with a marking criteria that is tedious and frustrating to go through I had to program the marking system.

Criteria for the essay:
1. The shortest word should get between 10 and 50 points (count the points based on Table 1)
(you should exclude one-letter words).
2. The longest word should get between 200 and 250 points.
3. There should be 5 or more different palindrome words in the essay (i.e. words reading the same backward as forward, e.g. “stats”).
4. The length of the essay should be between 50 and 100 words.
5. The average number of letters used in a word should be between 4 and 8, and the average number of points (see Table 1) for the words used in the essay should be between 20 and 60.
6. It is not allowed to have words that have more than 4 letters of type V (find the type for each letter in Table 1).

Task
1. For each of the six criteria mentioned above, print out a statement of whether it passes or fails.
2. Print out the shortest word, the longest word, the word with the lowest number of points, the word with the highest number of points, the least frequent word and the most frequent word.
3. Print out the number of times each word appears in the essay in an ascending order.
4. Print out the student’s name, the key, the secret of the essay, and the deciphered version of the secret.
5. Sort all words by their points and print out the one in the middle (in case the number of words is even, concatenate the two in the middle and print them out as one word without any spaces in between)


Table 1: Letters with the corresponding points and types
Letter A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
Point 10 21 7 2 19 18 4 8 6 11 14 3 9 22 1 23 17 5 25 13 12 26 24 16 20 15 
Type V C C C V C C C V C C C C C V C C C C C V C C C C C 
