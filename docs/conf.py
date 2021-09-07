# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
import sys
sys.path.insert(0, os.path.abspath('_themes'))
sys.path.insert(0, os.path.abspath('doxyrest-sphinx'))
# sys.path.insert(0, os.path.abspath('.'))

# -- Project information -----------------------------------------------------

project = 'OpenVINO Toolkit'
copyright = '2021, Intel'
author = 'Intel'

language = 'en'

html_context = {
    'current_version': 'latest',
    'versions': (('latest', '/en/latest/'), ('2022.1', '/en/2022.1/')),
    'languages': (('English', '/en/latest/'), ('Chinese', '/cn/latest/'))
}

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'openvino_sphinx_theme',
    'sphinx_inline_tabs',
    'sphinx_copybutton',
    'doxyrest',
    'cpplexer'
]

html_logo = '_static/logo.svg'

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store', 'openvino/inference-engine']


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = "openvino_sphinx_theme"

html_theme_path = ['_themes']

html_theme_options = {
    "navigation_depth": 5,
    "use_edit_page_button": True,
    "github_url": "https://github.com/ntyukaev/openvino",
}

html_context = {
    'current_version': 'latest',
    'current_language': 'English',
    'languages': (('English', '/en/latest'), ('Chinese', '/cn/latest')),
    'versions': (('latest', '/latest'), ('2022.1', '/2022.1'), ('2021.4', '/2021.4'),
                ('2021.3', '/2021.3'), ('2021.2', '/2021.2'), ('2021.1', '/2021.1'),
                 ('2020.4', '/2020.4'), ('2020.3', '/2020.3'), ('2020.2', '/2020.1'),
                  ('2020.1', '/2020.1'), ('2019_R3.1', '/2019_R3.1'), ('2019_R3', '/2019_R3'),
                   ('2019_R2', '/2019_R2'), ('2019_R1.1', '/2019_R1.1'),  ('2019_R1.01', '/2019_R1.01'),
                    ('2019_R1', '/2019_R1'), ('2018_R5', '/2018_R5'),),
    'download_docs_url': '/archives/2022.1.zip'
}

repositories = {
    'openvino': {
        'github_user': 'ntyukaev',
        'github_repo': 'openvino',
        'github_version': 'feature/ntyukaev/to-sphinx',
        'host_url': 'https://github.com'
    },
    'open_model_zoo': {
        'github_user': 'ntyukaev',
        'github_repo': 'open_model_zoo',
        'github_version': 'feature/read-the-docs',
        'host_url': 'https://github.com'
    }
}

doxygen_mapping_file = '@DOXYGEN_MAPPING_FILE@'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']


def setup(app):
    app.add_css_file('css/viewer.min.css')
    app.add_css_file('css/custom.css')
    app.add_js_file('js/viewer.min.js')
    app.add_js_file('js/custom.js')
    
