import pytest
from dp.edit_distance import getEditDistance

def test_editDistance():
    assert getEditDistance("kitten", "sitting") == 3
    assert getEditDistance("Sunday", "Saturday") == 3
    assert getEditDistance("Java", "JavaScript") == 6
    assert getEditDistance("hello", "") == 5
    assert getEditDistance("", "") == 0
