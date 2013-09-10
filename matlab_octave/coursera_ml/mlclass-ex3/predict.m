function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);

% You need to return the following variables correctly 
p = zeros(size(X, 1), 1);

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%
%A column for every example
a2 = zeros(25, size(X,1));

%a2 has dimensions of 25 rows and 5000 columns. Each column corresponds to one sample.
X = [ones(size(X, 1), 1) X];
a2 = sigmoid(Theta1 * X');

%add a row of ones to confirm with the dimesions
a2 = [ones(1, columns(a2));a2];
%a2 now has dimensions 26 X 5000, Theta2 is 10X26 a3 thus is 10X5000
a3 = zeros(10, 5000);
a3 = sigmoid(Theta2 * a2);
%a3 has 10 rows and 5000 columns. Each column corresponds to a training set

a3 = a3';
%each row is a point from the training set.
maxval = size(5000,1);
[maxval, p] = max(a3, [], 2);





% =========================================================================


end